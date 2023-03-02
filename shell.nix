# shell.nix
let
  old = import (fetchTarball "https://github.com/NixOS/nixpkgs-channels/archive/f22817d8d2bc17d2bcdb8ac4308a4bce6f5d1d2b.tar.gz") {};
  pkgs = import <u> {};
  compiler = "ghc902";
in
pkgs.mkShell {
  packages = [
    (pkgs.haskell.packages.${compiler}.ghcWithPackages (ps: with ps; [ sbv ]))
    pkgs.linuxKernel.packages.linux_5_15.perf
  ];
}
