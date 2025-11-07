cls
cd /d "%~dp0"

g++ main.cpp -Iinclude -Llib ^
    -lglfw3 -lopengl32 -lgdi32 -luser32 -lkernel32 -o app.exe

echo.
echo Build complete! Running app...
echo.
app.exe
pause
