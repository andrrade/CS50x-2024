from PIL import Image, ImageFilter

before = Image.open("yard.bmp")
after = before.filter(ImageFilter.BoXBlur(10))
after.save("out.bmp")
