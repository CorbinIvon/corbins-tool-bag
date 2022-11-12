#!/bin/bash

SALT=aaaaaaaa
# Escape special characters.
DESIRED_HASH=\$6\$aaaaaaaa\$mdOP7SumCDUT/N1JgclftYBzt2WsQZGDFRfQVNQOVq4XSCCYZme3qPDTYkjEPC3iyQv1MryMC149vz7QeYI1y1

character_array=('A' 'B' 'C' 'D' 'E' 'F' 'G' 'H' 'I' 'J' 'K' 'L' 'M' 'N' 'O' 'P' 'Q' 'R' 'S' 'T' 'U' 'V' 'W' 'X' 'Y' 'Z' 'a' 'b' 'c' 'd' 'e' 'f' 'g' 'h' 'i' 'j' 'k' 'l' 'm' 'n' 'o' 'p' 'q' 'r' 's' 't' 'u' 'v' 'w' 'x' 'y' 'z' '0' '1' '2' '3' '4' '5' '6' '7' '8' '9' '!' '@' '#' '$' '%' '^' '&' '(' ')' '_' '=' '+' ',' '.' '<' '>' '/' '\' '?' '~')
# Can not be empty
current_password=""
current_password_array=("$1" "$2" "$3" "$4" "$5" "$6" "$7" "$8" "$9" "${10}" "${11}" "${12}" "${13}" "${14}" "${15}" "${16}" "${17}" "${18}" "${19}" "${20}")
echo "Timestamp Started:" $(date +%Y-%m-%d\ %H\:%M\:%S) >> password-cracking.log
echo "Starting Characters:" ${current_password_array[@]} >> password-cracking.log
# Define Functions
function_get_next_char(){
  local current_char=$1
  for i in "${!character_array[@]}"; do
    # If current character is last character...
    if [[ "${character_array[81]}" = "${current_char}" ]]; then
      return 0
    fi
    # If current character exists in list...
    if [[ "${character_array[$i]}" = "${current_char}" ]]; then
      return $(expr ${i} + 1)
    fi
    # Start at the beginning...
  done
  return 0
}
function_increment_word(){

  if [ "${current_password_array[0]}" == "${character_array[81]}" ]; then
    if [ "${current_password_array[1]}" == "${character_array[81]}" ]; then
      if [ "${current_password_array[2]}" == "${character_array[81]}" ]; then
        if [ "${current_password_array[3]}" == "${character_array[81]}" ]; then
          if [ "${current_password_array[4]}" == "${character_array[81]}" ]; then
            if [ "${current_password_array[5]}" == "${character_array[81]}" ]; then
              if [ "${current_password_array[6]}" == "${character_array[81]}" ]; then
                if [ "${current_password_array[7]}" == "${character_array[81]}" ]; then
                  if [ "${current_password_array[8]}" == "${character_array[81]}" ]; then
                    if [ "${current_password_array[9]}" == "${character_array[81]}" ]; then
                      if [ "${current_password_array[10]}" == "${character_array[81]}" ]; then
                        if [ "${current_password_array[11]}" == "${character_array[81]}" ]; then
                          if [ "${current_password_array[12]}" == "${character_array[81]}" ]; then
                            if [ "${current_password_array[13]}" == "${character_array[81]}" ]; then
                              if [ "${current_password_array[14]}" == "${character_array[81]}" ]; then
                                if [ "${current_password_array[15]}" == "${character_array[81]}" ]; then
                                  if [ "${current_password_array[16]}" == "${character_array[81]}" ]; then
                                    if [ "${current_password_array[17]}" == "${character_array[81]}" ]; then
                                      if [ "${current_password_array[18]}" == "${character_array[81]}" ]; then
                                        if [ "${current_password_array[19]}" == "${character_array[81]}" ]; then
                                          echo "End of brute force! Password not found..."
                                          exit 0
                                        fi
                                        function_get_next_char ${current_password_array[19]}
                                        current_password_array[19]="${character_array[$?]}"
                                      fi
                                      function_get_next_char ${current_password_array[18]}
                                      current_password_array[18]="${character_array[$?]}"
                                    fi
                                    function_get_next_char ${current_password_array[17]}
                                    current_password_array[17]="${character_array[$?]}"
                                  fi
                                  function_get_next_char ${current_password_array[16]}
                                  current_password_array[16]="${character_array[$?]}"
                                fi
                                function_get_next_char ${current_password_array[15]}
                                current_password_array[15]="${character_array[$?]}"
                              fi
                              function_get_next_char ${current_password_array[14]}
                              current_password_array[14]="${character_array[$?]}"
                            fi
                            function_get_next_char ${current_password_array[13]}
                            current_password_array[13]="${character_array[$?]}"
                          fi
                          function_get_next_char ${current_password_array[12]}
                          current_password_array[12]="${character_array[$?]}"
                        fi
                        function_get_next_char ${current_password_array[11]}
                        current_password_array[11]="${character_array[$?]}"
                      fi
                      function_get_next_char ${current_password_array[10]}
                      current_password_array[10]="${character_array[$?]}"
                    fi
                    function_get_next_char ${current_password_array[9]}
                    current_password_array[9]="${character_array[$?]}"
                  fi
                  function_get_next_char ${current_password_array[8]}
                  current_password_array[8]="${character_array[$?]}"
                fi
                function_get_next_char ${current_password_array[7]}
                current_password_array[7]="${character_array[$?]}"
              fi
              function_get_next_char ${current_password_array[6]}
              current_password_array[6]="${character_array[$?]}"
            fi
            function_get_next_char ${current_password_array[5]}
            current_password_array[5]="${character_array[$?]}"
          fi
          function_get_next_char ${current_password_array[4]}
          current_password_array[4]="${character_array[$?]}"
        fi
        function_get_next_char ${current_password_array[3]}
        current_password_array[3]="${character_array[$?]}"
        echo "Checkpoint: ${current_password_array[3]}" >> password-cracking.log
      fi
      function_get_next_char ${current_password_array[2]}
      current_password_array[2]="${character_array[$?]}"
    fi
    function_get_next_char ${current_password_array[1]}
    current_password_array[1]="${character_array[$?]}"
  fi


  function_get_next_char ${current_password_array[0]}
  current_password_array[0]="${character_array[$?]}"

  current_password="${current_password_array[0]}${current_password_array[1]}${current_password_array[2]}${current_password_array[3]}${current_password_array[4]}${current_password_array[5]}${current_password_array[6]}${current_password_array[7]}${current_password_array[8]}${current_password_array[9]}${current_password_array[10]}${current_password_array[11]}${current_password_array[12]}${current_password_array[12]}${current_password_array[13]}${current_password_array[14]}${current_password_array[15]}${current_password_array[16]}${current_password_array[17]}${current_password_array[18]}${current_password_array[19]}"
}

while [ ! -f ./password.result ];
do
  # Test the hash, increment the hash.
  CURRENT_HASH=$(mkpasswd -m sha-512 $current_password -s $SALT)
  echo $current_password
  # echo $CURRENT_HASH
  # echo ""
  if [ "$CURRENT_HASH" == "$DESIRED_HASH" ]; then
    echo $current_password > password.result
  fi
  function_increment_word
done
echo "PASSWORD FOUND! View password.result. Remove to restart process."
