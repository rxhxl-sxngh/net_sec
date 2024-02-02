import subprocess

matching_amounts = []

for j in range(1, 901):  # Loop through numbers 1 to 900
    plainstr = "$" + str(j) + "B\n"
    padded_str = plainstr.ljust(256, '\x00')

    with open("msg.txt", "wb") as wf:
        wf.write(padded_str)

    # Encrypt the message
    subprocess.call("openssl rsautl -encrypt -raw -inkey /problems/known-plaintext-rsa_16_51513073d81c14fe1bbbe31fb6593618/treasurypub.pem -pubin -in msg.txt -out msg.txt.enc", shell=True)

    # Base64 encode the encrypted message and append to bankmessage.txt
    subprocess.call("base64 msg.txt.enc >> bankmessage.txt", shell=True)

    # Check if the bankmessage is in messages.txt using grep
    grep_command = "grep -n -f bankmessage.txt /problems/known-plaintext-rsa_16_51513073d81c14fe1bbbe31fb6593618/messages.txt"
    result = subprocess.Popen(grep_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, _ = result.communicate()

    if result.returncode == 0:
        # Extract line number from grep output
        line_number = int(output.strip().split(':')[0])
        matching_amounts.append(("$" + str(j) + "B", line_number))

    # Clear bankmessage.txt
    subprocess.call("echo -n '' > bankmessage.txt", shell=True)

# Sort matching amounts based on line numbers
matching_amounts.sort(key=lambda x: x[1])

# Write sorted matching amounts to a file
with open("matching_amounts_sorted.txt", "w") as output_file:
    for amount, line_number in matching_amounts:
        output_file.write("{} - Line Number: {}\n".format(amount, line_number))