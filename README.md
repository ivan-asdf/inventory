### Building
In order to compile the program you must have `clang`, `clang++`, `make` and  C/C++ standard library.
#### Linux
Install the build dependencies with whatever package management system your distribution has.

Ubuntu
```
sudo apt update && sudo apt install -y clang make libc++-dev libc++abi-dev
```
Redhat/CentOS
```
sudo dnf install -y clang make libstdc++-devel
```
#### Windows
Download Microsoft [Visual Studio build tools installer](https://visualstudio.microsoft.com/visual-cpp-build-tools).

select and install **Desktop development with C++**

In a powershell run:
```
winget install ezwinports.make
winget install LLVM.LLVM
```
In a powershell instance ran as administrator run:
```
[System.Environment]::SetEnvironmentVariable('Path', $env:Path + ';C:\Program Files\LLVM\bin', [System.EnvironmentVariableTarget]::Machine)
```
*to make the `clang` and `clang++` commands accesible from powershell*
#### Build command
```make build```

The output will be `program_inventory.exe`
