import subprocess

# Load banks from file
myfile = open('/problems/known-plaintext-rsa_16_51513073d81c14fe1bbbe31fb6593618/banks.txt', 'r')
lines = myfile.readlines()
some_banks = [line.strip() for line in lines]
myfile.close()

matching_banks = []

for j in range(len(some_banks)):
    plainstr = "How much to " + some_banks[j] + "?\n"
    padded_str = plainstr.ljust(256, '\x00')

    with open("msg.txt", "wb") as wf:
        wf.write(padded_str)

    # Encrypt the message
    subprocess.call("openssl rsautl -encrypt -raw -inkey /problems/known-plaintext-rsa_16_51513073d81c14fe1bbbe31fb6593618/presidentpub.pem -pubin -in msg.txt -out msg.txt.enc", shell=True)

    # Base64 encode the encrypted message and append to bankmessage.txt
    subprocess.call("base64 msg.txt.enc >> bankmessage.txt", shell=True)

    # Check if the bankmessage is in messages.txt using grep
    grep_command = "grep -n -f bankmessage.txt /problems/known-plaintext-rsa_16_51513073d81c14fe1bbbe31fb6593618/messages.txt"
    result = subprocess.Popen(grep_command, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, _ = result.communicate()

    if result.returncode == 0:
        # Extract line number from grep output
        line_number = int(output.strip().split(':')[0])
        matching_banks.append((some_banks[j], line_number))

    # Clear bankmessage.txt
    subprocess.call("echo -n '' > bankmessage.txt", shell=True)

# Sort matching banks based on line numbers
matching_banks.sort(key=lambda x: x[1])

# Write sorted matching banks to a file
with open("matching_banks_sorted.txt", "w") as output_file:
    for bank, line_number in matching_banks:
        output_file.write("{} - Line Number: {}\n".format(bank, line_number))

