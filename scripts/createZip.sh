plugin_name="VPEQ"
dir_win="../win_build/VST3/Release"
dir_mac="../mac_build/VST3/Release"

readme="README.txt"
text="Thanks for downloading my plugin!

Installation (Windows):
    Copy the .vst3 plugin file to C:\Program Files\Common Files\VST3

Installation (Mac):
    Copy the .vst3 plugin file to Library/Audio/Plug-ins/VST3"

create_zip_contents() {
    echo "Creating .zip with $dir_win/${plugin_name}_VST.vst3"
    mkdir $plugin_name
    cp -r $dir_win/${plugin_name}_VST.vst3 $plugin_name/$plugin_name.vst3

    echo -e "$text" > $plugin_name/$readme
    zip -r VPEQ.zip VPEQ/
}

if [ -d $dir_win ] 
then
    echo "Creating .zip with $dir_win/${plugin_name}_VST.vst3"
    mkdir $plugin_name
    cp -r $dir_win/${plugin_name}_VST.vst3 $plugin_name/$plugin_name.vst3

    echo -e "$text" > $plugin_name/$readme
    zip -r VPEQ.zip VPEQ/
elif [ -d $dir_mac ]
then
    echo "Creating .zip with $dir_mac/${plugin_name}_VST.vst3"
    mkdir $plugin_name
    cp -r $dir_mac/${plugin_name}_VST.vst3 $plugin_name/$plugin_name.vst3

    echo -e "$text" > $plugin_name/$readme
    zip -r VPEQ.zip VPEQ/
else
    echo "Directories $dir_mac and $dir_win do not exist." 
    exit 9999
fi