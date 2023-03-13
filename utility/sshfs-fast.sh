if [ "$#" -eq 0 ]; then
    # No parameters were passed.
    echo "Usage: sshfs-quick ssh-host:/path/to/folder"
    exit 1
fi

_DIR="$(pwd)"
_MAKE_DIR="$(echo "$1" | cut -d: -f2 | xargs basename)"

mkdir -p "$_MAKE_DIR"
if test -d "$_DIR/$_MAKE_DIR"; then
    # The directory exists.
    if [ -z "$(find "$_DIR/$_MAKE_DIR" -mindepth 1 -maxdepth 1)" ]; then
        # The directory is empty.
        sshfs "$1" "$_MAKE_DIR"
        if [ "$?" -ne 0 ]; then
            # The sshfs command failed.
            echo "sshfs failed. Exit code $?"
            rmdir "$_MAKE_DIR"
            exit 1
        fi
    else
        # The directory is not empty.
        echo "The directory $_MAKE_DIR contains files. Can not sshfs."
        echo "Please move to a different directory or use the normal sshfs command."
        exit 1
    fi
fi
