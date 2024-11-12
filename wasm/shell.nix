{ pkgs ? import <nixpkgs> {}}:
pkgs.mkShell {
  packages = with pkgs; [
    gcc
    clang
    gnumake
    gdb
    wabt
    wasmtime
  ];
}
