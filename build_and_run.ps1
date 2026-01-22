# Stop the script if any command fails
$ErrorActionPreference = "Stop"

# Optional: print each command
Write-Host "Configuring project..."
cmake -S . -B build

Write-Host "Building project..."
cmake --build build

Write-Host "Running executable..."
.\build\main.exe

Write-Host "`nProgram stopped`n"