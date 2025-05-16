cat << EOF > .clangd
CompileFlags:
  Add:
    - "-Wall"
    - "-Wextra"
    - "-I$(realpath LPC1769)"
    - "-ferror-limit=0"

Diagnostics:
  UnusedIncludes: Strict
EOF
