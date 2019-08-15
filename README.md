# cpp-workspace
This is a C++ environment on VSCode+Docker integration for writing trivial code.

Here "trivial code" means programs written in single .cpp file. I'm using this environment to write programs for online code judge like http://judge.u-aizu.ac.jp/onlinejudge/

## Requirements

- Docker
- Visual Studio Code
  - Remote Development extension

## How to run the sample(sum up numbers)

1. `git clone git@github.com:mytinylabo/cpp-workspace.git`
2. Launch VSCode and open `cpp-dev` directory by `Remote-Containers: Open Folder in Container...`
3. Wait for the container to be built and up(takes some time)
4. Open sample/main.cpp in VSCode
5. Hit F5 to build and run the active file
   - the result comes in `cppdbg: a.out` session in the terminal tab
