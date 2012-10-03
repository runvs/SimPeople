mkdir vs2010
cd vs2010
cmake -DCMAKE_MAKE_PROGRAM=C:/Windows/Microsoft.NET/Framework/v4.0.30319/MSBuild.exe -G "Visual Studio 10" ..
REM cmake -G "Visual Studio 10" ..
cd ..
