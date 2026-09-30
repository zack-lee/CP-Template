import os
import json
import re

def to_snake_case(name):
    # Handle already-snake or all-lower names
    s = re.sub(r'([A-Z]+)([A-Z][a-z])', r'\1_\2', name)
    s = re.sub(r'([a-z0-9])([A-Z])', r'\1_\2', s)
    return s.lower()

SOURCES = [
    ("content", {"cpp,c": [".h", ".cpp"], "python": [".py"]}),
    ("pyrival",  {"python": [".py"]}),
]
OUTPUT = ".vscode/cp-templates.code-snippets"

SKIP_FILES = {"__init__.py", "version.py"}

snippets = {}
seen_prefixes = {}

for src_dir, scope_map in SOURCES:
    ext_scope = {e: scope for scope, exts in scope_map.items() for e in exts}

    for root, dirs, files in os.walk(src_dir):
        dirs[:] = [d for d in dirs if d != ".svn"]
        for filename in sorted(files):
            if filename in SKIP_FILES:
                continue
            ext = os.path.splitext(filename)[1]
            if ext not in ext_scope:
                continue

            filepath = os.path.join(root, filename)
            rel = os.path.relpath(filepath, src_dir)
            name = os.path.splitext(filename)[0]

            prefix = to_snake_case(name) if src_dir == "pyrival" else name
            if prefix in seen_prefixes and seen_prefixes[prefix] != filepath:
                parent = os.path.basename(root)
                prefix = f"{parent}/{to_snake_case(name) if src_dir == 'pyrival' else name}"
            seen_prefixes.setdefault(prefix, filepath)

            with open(filepath, "r", encoding="utf-8", errors="replace") as f:
                raw = f.read()

            lines = raw.rstrip("\n").split("\n")
            body = [l.replace("\\", "\\\\").replace("$", "\\$") for l in lines]

            snippets[f"{src_dir}/{rel}"] = {
                "scope": ext_scope[ext],
                "prefix": prefix,
                "body": body,
                "description": rel,
            }

os.makedirs(".vscode", exist_ok=True)
with open(OUTPUT, "w", encoding="utf-8") as f:
    json.dump(snippets, f, indent=2, ensure_ascii=False)

print(f"Generated {len(snippets)} snippets -> {OUTPUT}")
