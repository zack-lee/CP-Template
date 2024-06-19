#!/bin/bash

function check_setup {
    grep -q "# CP Template Start" ~/.bashrc
}

function setup_bashrc {
    cat << 'EOF' >> ~/.bashrc


# CP Template Start
alias mkcpp="~/CP-Template/populate.py"
co() {
	g++ -std=c++17 -O2 -DDEBUG_ENABLED -Wall -Wextra -pedantic -Wshadow -Wformat=2 \
    -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond \
    -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion $1.cpp -o $1 
}
co_no_debug() {
	g++ -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 \
    -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond \
    -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion $1.cpp -o $1 
}
run() {
    local program="$1"
    shopt -s nullglob  # Enable nullglob option to handle case with no matches
    local input_files=("${program}"*.in)
    echo "$input_files"
    
    if [ ${#input_files[@]} -eq 0 ]; then
        ./"$program"
    else
        for input_file in "${input_files[@]}"; do
            cat "$input_file"
            ./"$program" < "$input_file" > "${input_file%.in}.out"
            if [ -f "${input_file%.in}.ans" ]; then
                diff -b "${input_file%.in}.ans" "${input_file%.in}.out" 
            else 
                echo "----------------------"
                cat "${input_file%.in}.out"
            fi
            echo ""
        done
    fi
}
crun() {
    co "$1" && echo "Compiled!" && run "$1" "$2"
}
ccrun() {
    co_no_debug "$1" && echo "Compiled!" && run "$1" "$2"
}
up(){
    local old="$PWD"
    for i in $(seq "${1:-1}"); do
        cd ..
    done
    OLDPWD="$old"
}
back() {
    cd $OLDPWD
}
# CP Template End
EOF
}

function uninstall_bashrc {
    sed -i '/# CP Template Start/,/# CP Template End/d' ~/.bashrc
}

# Main script logic
if [[ "$1" == "--uninstall" ]]; then
    if check_setup; then
        echo "Uninstalling bashrc functions..."
        uninstall_bashrc
        echo "Uninstallation complete. Please restart your shell."
    else
        echo "Setup not found in ~/.bashrc. No changes made."
    fi
else
    if ! check_setup; then
        echo "Setting up bashrc functions..."
        setup_bashrc
        echo "Setup complete. Please restart your shell."
    else
        echo "Setup already exists in ~/.bashrc. No changes made."
    fi
fi