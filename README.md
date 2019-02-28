# Hexe

`Hexe` is a minimal hexdumping tool. No fancy features.

## Compilation

Check `config.mk` for build options. Default is `clang -O2 -std=c99 -Wall`.

Run `make`.

## Usage

`hexe [infile] [outfile]`. Omitting either or using - uses stdin/stdout.
