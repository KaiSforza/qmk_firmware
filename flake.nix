{
  description = "Description for the project";

  inputs = {
    flake-parts.url = "github:hercules-ci/flake-parts";
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    devshell.url = "github:numtide/devshell";
  };

  outputs = inputs@{ flake-parts, devshell, ... }:
    flake-parts.lib.mkFlake { inherit inputs; } {
      imports = [
        # To import a flake module
        # 1. Add foo to inputs
        # 2. Add foo as a parameter to the outputs function
        # 3. Add here: foo.flakeModule
        inputs.devshell.flakeModule
      ];
      systems = [ "x86_64-linux" "aarch64-linux" "aarch64-darwin" "x86_64-darwin" ];
      perSystem = { config, self', inputs', pkgs, system, ... }: {
        # Per-system attributes can be defined here. The self' and inputs'
        # module parameters provide easy access to attributes of the same
        # system.
        # Equivalent to  inputs'.nixpkgs.legacyPackages.hello;
        devshells = {
            default = {
                motd = "";
                env = [
                    #{name = "QMK_FIRMWARE"; value = ./../qmk_firmware; }
                    {name = "QMK_HOME"; value = "/home/creyo/git/qmk_firmware"; }
                ];
                packages = [
                    pkgs.qmk
                ];
            };
        };

      };
      flake = { };
    };
}
