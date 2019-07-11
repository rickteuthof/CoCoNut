import argparse
import subprocess
import configparser
import sys
import os.path
import shutil
from pathlib import Path

class CoconutParser(object):
    path = Path("CoCoNut")
    dsl = Path("CoCoNut/dsl")
    main_dsl = Path("CoCoNut/dsl/main.coconut")
    include = Path("CoCoNut/include")
    source = Path("CoCoNut/src")
    config = configparser.ConfigParser()
    original_coconut_dir = None

    def __init__(self):
        parser = argparse.ArgumentParser(description="Process CoCoNut commands.",
            usage="coconut <command> [args]")
        parser.add_argument('command', nargs='?', default=False, help="Command to run")
        parser.add_argument('--list', action="store_true", help="Show a list of possible commands to run")

        args = parser.parse_args(sys.argv[1:2])

        if not args.command:
            if args.list:
                self.print_commands()
            else:
                parser.print_help()
            exit(1)

        if not hasattr(self, args.command):
            print("Unrecognized command")
            parser.print_help()
            exit(1)

        self.config.read("/home/damian/.config/CoCoNut/config")
        self.original_coconut_dir = Path(self.config['Paths']['install_dir'])
        getattr(self, args.command)()

    def build(self):
        # TODO: check if CoCoNut dir exists.
        subprocess.run([self.original_coconut_dir.joinpath("bin/cocogen"),
            str(self.dsl.joinpath("main.coconut")),
            "--source-dir",
            str(self.source),
            "--header-dir",
            str(self.include),
            "--consistency-checks",
            "--breakpoints"])


    def init(self):
        if not os.path.exists(self.path):
            print("[coconut] Creating the CoCoNut directory.")
            self.path.mkdir()
            self.dsl.mkdir()
            self.include.mkdir()
            self.include.joinpath("core").mkdir()
            self.include.joinpath("generated").mkdir()
            if self.source != self.include:
                self.source.mkdir()
                self.source.joinpath("ccnstd").mkdir()
                self.source.joinpath("generated").mkdir()
                self.source.joinpath("core").mkdir()

            self.include.joinpath("ccnstd").mkdir()
            self.include.joinpath("ccnstd/lib").mkdir()
            self.main_dsl.touch()

            for p in self.original_coconut_dir.joinpath("include/core").iterdir():
                if p.match("*.h") and p.is_file():
                    shutil.copy(p, self.include.joinpath("core"))

            for p in self.original_coconut_dir.joinpath("src/core").iterdir():
                if p.match("*.c") and p.is_file():
                    shutil.copy(p, self.source.joinpath("core"))

            for p in self.original_coconut_dir.joinpath("lib/CoCoNut-lib/source").iterdir():
                if (p.match("*.c") or p.match("*.h")) and p.is_file():
                    shutil.copy(p, self.source.joinpath("ccnstd"))

            for p in self.original_coconut_dir.joinpath("lib/CoCoNut-lib/include/lib").iterdir():
                if p.match("*.h") and p.is_file():
                    shutil.copy(p, self.include.joinpath("ccnstd/lib"))

        else:
            print("[coconut] Already a CoCoNut directory present.")



    def print_commands(self):
        print("List of commands to use:")
        print("build | Build the required coconutlib")
        print("init  | Initialise a new project")


def main():
    CoconutParser()

if __name__ == '__main__':
    main()
