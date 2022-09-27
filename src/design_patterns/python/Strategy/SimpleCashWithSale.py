# -*- coding:utf-8 -*-
'''
@File    :   Untitled-1
@Time    :   2022/09/23 11:28:03
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
@License :

    (c) Copyright 2022 SheltonXiao

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or(at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY;without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
    GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with this program.If not, see < https: //www.gnu.org/licenses/>.
'''

import tkinter
import tkinter.ttk

class CashWindow(object):
    def __init__(self):
        self.total = 0
        root = tkinter.Tk()
        self.label1 = tkinter.Label(root,text="单价：")
        self.txtPrice = tkinter.Entry(root,width = 24,)
        self.label2 = tkinter.Label(root,text="数量：")
        self.txtNum = tkinter.Entry(root,width = 24,)
        self.ibxList = tkinter.Text(root,width = 45, height = 10)
        self.label4 = tkinter.Label(root,text="总计：")
        
        self.iblResult = tkinter.StringVar()
        self.iblResult.set("%.2f"%self.total)
        self.result = tkinter.Label(root,textvariable=self.iblResult, height = 2, font = ('TimeNewsRoman',24))
        self.button = tkinter.Button(root,text="确定",width = 10,command = self.btnOk_click)
        self.buttonReset = tkinter.Button(root,text="重置",width = 10,command = self.btnReset_click)

        self.label3 = tkinter.Label(root,text="计算方式：")
        self.comboVar = tkinter.StringVar()
        self.combobox = tkinter.ttk.Combobox(root, textvariable = self.comboVar,width = 22,)
        self.combobox['value'] = ("正常收费","打8折","打7折","打5折")
        self.combobox.current(0)
        self.layout()
        root.mainloop()
    
    def refresh(self):
        self.txtPrice.delete('0','end')
        self.txtNum.delete('0','end')

    def layout(self):
        self.label1.grid(row = 0, column = 0, padx = (10,0), pady = 10)
        self.txtPrice.grid(row = 0, column = 1, pady = 10,padx = (0,5),)
        self.label2.grid(row = 1, column = 0, padx = (10,0))
        self.txtNum.grid(row = 1, column = 1,padx = (0,5),)
        self.label3.grid(row = 2, column = 0, padx = (10,0))
        self.combobox.grid(row = 2, column = 1,padx = (0,5),pady = 10)

        self.ibxList.grid(row = 4, column = 0,columnspan = 4,padx = (5,5),pady = 10)
        self.label4.grid(row = 5, column = 0, padx = (10,0))
        self.result.grid(row = 5, column = 1,columnspan = 3, rowspan = 2)
        self.button.grid(row = 0, column = 2, columnspan = 2,pady = 10,  padx = (0,10))
        self.buttonReset.grid(row = 1, column = 2, columnspan = 2, padx = (0,10))

    def btnReset_click(self):
        self.total = 0
        self.ibxList.delete('1.0','end')
        self.iblResult.set("%.2f"%self.total)
        self.refresh()

    # 主要部分
    def btnOk_click(self):
        if self.comboVar.get() == "正常收费":
            totalPrice = float(self.txtPrice.get()) * float(self.txtNum.get())
        elif self.comboVar.get() == "打8折":
            totalPrice = float(self.txtPrice.get()) * float(self.txtNum.get()) * 0.8
        elif self.comboVar.get() == "打7折":
            totalPrice = float(self.txtPrice.get()) * float(self.txtNum.get()) * 0.7
        elif self.comboVar.get() == "打5折":
            totalPrice = float(self.txtPrice.get()) * float(self.txtNum.get()) * 0.5
        self.total = self.total + totalPrice
        self.ibxList.insert('end',"单价："+self.txtPrice.get()+" 数量："
                            +self.txtNum.get()+" "+self.comboVar.get()+" 合计：%.2f"%(totalPrice)+"\n")
        self.iblResult.set("%.2f"%self.total)
        self.refresh()

if __name__ == '__main__':
    CashWindow()
    