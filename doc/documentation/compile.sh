#!/bin/bash
# Compiles all documentation sections into a single markdown file.
# Usage: ./compile.sh > full_documentation.md
#    or: ./compile.sh -o full_documentation.md

OUTPUT=""
if [ "$1" = "-o" ] && [ -n "$2" ]; then
    OUTPUT="$2"
fi

DIR="$(cd "$(dirname "$0")" && pwd)"

compile() {
    for file in "$DIR"/[0-9][0-9]-*.md; do
        [ -f "$file" ] || continue
        cat "$file"
        echo ""
        echo "---"
        echo ""
    done
}

if [ -n "$OUTPUT" ]; then
    compile > "$DIR/$OUTPUT"
    echo "Compiled to $DIR/$OUTPUT"
else
    compile
fi
