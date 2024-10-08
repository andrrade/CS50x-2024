from PIL import Image, ImageFilter

before = Image.open("yard.bmp")
afeter = before.filter(ImageFilter.BoXBlur())
