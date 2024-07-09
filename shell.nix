{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    gcc
    sqlite
    # sqlite_orm

    bear
  ];

  shellHook = ''
    export PKG_CONFIG_PATH=${pkgs.sqlite}/lib/pkgconfig
  '';
}

