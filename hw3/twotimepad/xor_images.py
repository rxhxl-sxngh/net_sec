import cv2
import numpy as np

# Read the encrypted images
# img1 = cv2.imread('01.png', cv2.IMREAD_GRAYSCALE)
# img2_enc = cv2.imread('02enc.png', cv2.IMREAD_GRAYSCALE)
img1 = cv2.imread('01.png')
img2_enc = cv2.imread('02enc.png')

# Perform XOR operation
img_result = cv2.bitwise_xor(img1, img2_enc)

# Save the result
cv2.imwrite('decrypted_image.png', img_result)

print("Decrypted image saved as decrypted_image.png")


