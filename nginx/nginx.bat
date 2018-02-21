@ECHO OFF

cd C:\nginx

nginx -s stop
taskkill /F /IM nginx.exe
start nginx