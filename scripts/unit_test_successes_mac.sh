# checks if mac_build folder exists - if so, then executes the unit tests

if [ ! -d "../mac_build/project_source/cmake/unit_test/Debug/" ] 
then
    echo "Directory .../mac_build/project_source/cmake/unit_test/Debug/ doesn't exist."
else
    ./../mac_build/project_source/cmake/unit_test/Debug/unit_tests -s
fi