import os
import sys
from PIL import Image

# Set of ASCII characters from darkest to lightest
# ASCII_SET = ["@", "#", "&", "%", "0", "o", ".", " "]
ASCII_SET = [" ", " ", " ", " ", ".", ",", "!", "~","*", "&", "#", "?", "0", "5", "&", ")", "#", "%", "+","^", "`", ",", ".", " ", " ", " ", " "]

def resize_image(image, new_width=100):
    aspect_ratio = 0.5  # accounts for character height vs width
    new_height = int(image.height * aspect_ratio * new_width / image.width)
    return image.resize((new_width, new_height))

def convert_to_grayscale(image):
    return image.convert("L")

def map_pixels_to_ascii(pixels):
    ascii_pixels = []
    for px in pixels:
        index = int(px / 256 * len(ASCII_SET))
        ascii_pixels.append(ASCII_SET[min(index, len(ASCII_SET) - 1)])
    return ascii_pixels

def pixel_lines(ascii_pixels, width):
    return [
        ''.join(ascii_pixels[i:i + width])
        for i in range(0, len(ascii_pixels), width)
    ]

def process_image(path):
    try:
        with Image.open(path) as im:
            im = resize_image(im)
            im = convert_to_grayscale(im)
            ascii_pixels = map_pixels_to_ascii(list(im.getdata()))
            lines = pixel_lines(ascii_pixels, im.width)

            # Print to terminal
            for line in lines:
                print(line)

            # Save to text file
            output_file = os.path.join(path, "txt.output/")
            output_file = os.path.splitext(path)[0] + "_ascii.txt"
            with open(output_file, "w") as f:
                f.write('\n'.join(lines))
            print(f"\nSaved to {output_file}")
    except OSError:
        print(f"Could not process: {path}")

if __name__ == "__main__":
    for image_path in sys.argv[1:]:
        process_image(image_path)
