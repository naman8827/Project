import xlrd
import serial

loc = ("F:\\Coding\\follow_bot.xlsx")
ser1 = serial.Serial('COM8', 9600)
wb = xlrd.open_workbook(loc)
sheet = wb.sheet_by_index(0)


sheet.cell_value(0, 0)

p = []
q = []
for i in range(sheet.nrows):
    x = sheet.cell_value(i, 0)
    y = sheet.cell_value(i, 1)
    p.append(x)
    q.append(y)
    print(p[i])
    print(q[i])
    ser1.write(bytes(p[i],q[i]))
