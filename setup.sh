#!/bin/bash

function check_setup {
    grep -q "# CP Template Start" ~/.bashrc
}

function setup_bashrc {
    cat << 'EOF' >> ~/.bashrc


# CP Template Start
alias mkcpp="~/CP-Template/populate.py"
co() {
	g++ -std=c++17 -O2 -Wall -Wextra -pedantic -Wshadow -Wformat=2 -Wfloat-equal -Wconversion -Wlogical-op -Wshift-overflow=2 -Wduplicated-cond -Wcast-qual -Wcast-align -Wno-unused-result -Wno-sign-conversion $1.cpp -o $1 
}
run() {
	if [$# -eq 2]
	then ./$1 < $1$2.in
	else ./$1
	fi
}
crun() {
    co() && echo "Compiled!" && run $1 $2
}
up (){
    local old="$PWD"
    for i in $(seq "${1:-1}"); do
        cd ..
    done
    OLDPWD="$old"
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