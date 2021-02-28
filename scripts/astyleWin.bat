# created by Ryan Puhalovich - https://github.com/rpuhalovich/

call cd ../project_source/source/aax_source
call astyle --style=java --recursive *.cpp,*.h
call cd ../au_source
call astyle --style=java --recursive *.cpp,*.h
call cd ../CustomControls
call astyle --style=java --recursive *.cpp,*.h
call cd ../FFTW
call astyle --style=java --recursive *.cpp,*.h
call cd ../PluginKernel
call astyle --style=java --recursive *.cpp,*.h
call cd ../PluginObjects
call astyle --style=java --recursive *.cpp,*.h
call cd ../vst_source
call astyle --style=java --recursive *.cpp,*.h

call cd ../
DEL /S /Q *.ORIG
