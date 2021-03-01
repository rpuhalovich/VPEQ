# created by Ryan Puhalovich - https://github.com/rpuhalovich/

plugin_name="VPEQ"
readme="README.txt"
readme_text="Thanks for downloading my plugin!

Installation (Windows):
    Copy the ${plugin_name}.vst3 plugin file to C:\Program Files\Common Files\VST3

Installation (Mac):
    Copy the ${plugin_name}.vst3 plugin file to Library/Audio/Plug-ins/VST3"

if [ -z "$1" ]
  then
    echo "Usage: ./createZip.sh <version number>"
    exit 9999
fi

ver_num="$1"
dir_win="../win_build/VST3/Release"
dir_mac="../mac_build/VST3/Release"

create_zip_contents() {
    mkdir $plugin_name
    cp -r $1/${plugin_name}_VST.vst3 $plugin_name/$plugin_name.vst3

    echo -e "$readme_text" > $plugin_name/$readme
    zip -rqm VPEQ_${ver_num}.zip VPEQ/
    echo "Created ${plugin_name}.zip with $1/${plugin_name}_VST.vst3"
}

if [ -d $dir_win ] 
then
    create_zip_contents $dir_win
elif [ -d $dir_mac ]
then
    create_zip_contents $dir_mac
else
    echo "Directories $dir_mac and $dir_win do not exist." 
    exit 9999
fi