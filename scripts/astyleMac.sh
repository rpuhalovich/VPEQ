cd ../project_source/source/aax_source
astyle --style=java --recursive "*.cpp,*.h"
cd ../au_source
astyle --style=java --recursive "*.cpp,*.h"
cd ../CustomControls
astyle --style=java --recursive "*.cpp,*.h"
cd ../FFTW
astyle --style=java --recursive "*.cpp,*.h"
cd ../PluginKernel
astyle --style=java --recursive "*.cpp,*.h"
cd ../PluginObjects
astyle --style=java --recursive "*.cpp,*.h"
cd ../vst_source
astyle --style=java --recursive "*.cpp,*.h"

cd ../
find . -type f -name '*.orig' -delete
