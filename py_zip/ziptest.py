import py_zip

c={"a.txt":"1","b.txt":"2"}
t=py_zip.zip_to_string(c)

f=open("data.zip", "wb")
f.write(t)
f.close()
