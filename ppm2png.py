from PIL import Image

with open("output.ppm", "r") as f:
    mode = f.readline()
    size = tuple(map(int, f.readline().split()))
    max_col = f.readline()
    out = Image.new("RGB", tuple(size))
    i=0
    j=0
    while i != size[0]:
        colors = list(map(int, f.readline().split()))
        out.putpixel((i,j),tuple(colors))
        j+=1
        if j == size[1]:
            j = 0
            i += 1
            print(f"{int(i/size[0]*100)}%\r")
    print()
        
    
    out.save("output.png")