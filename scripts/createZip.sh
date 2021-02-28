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
    mkdir $plugin_name
    cp -r $dir_win/${plugin_name}_VST.vst3 $plugin_name/$plugin_name.vst3

    echo -e "$text" > $plugin_name/$readme
    zip -rqm VPEQ.zip VPEQ/
    echo "Created ${plugin_name}.zip with $1/${plugin_name}_VST.vst3"
}

if [ -d $dir_win ] 
then
    create_zip_contents $dir_win
elif [ -d $dir_mac ]
then
    create_zip_contents $dir_win
else
    echo "Directories $dir_mac and $dir_win do not exist." 
    exit 9999
fi