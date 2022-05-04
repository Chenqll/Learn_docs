# s是十进制表示，h是转换后的十六进制表示
s = 15
i = int(s)
h = hex(i).split('x')[1]
print (h)

# s是十六进制表示，i是转换后的十进制表示
s = 'f'
i = int(s, 16)
print (i)