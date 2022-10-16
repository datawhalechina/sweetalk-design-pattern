# -*- coding:utf-8 -*-
'''
@File    :   StrategyCash.py
@Time    :   2022/09/23 13:37:04
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''

# here put the import lib
import tkinter
import tkinter.ttk

class CashSuper(object):
    def __init__(self):
        pass
    def accept_cash(self,money):
        pass

# 正常收费
class CashNormal(CashSuper):
    def accept_cash(self,money):
        return money

# 打折收费
class CashRebate(CashSuper):
    __moneyRebate = 1
    def cash_rebate(self,moneyRebateStr):
        self.__moneyRebate = float(moneyRebateStr)
    def accept_cash(self,money):
        return money*self.__moneyRebate

# 返利收费
class CashReturn(CashSuper):
    __moneyCondition = 0
    __moneyReturn = 0
    def cash_return(self,moneyConditionStr,moneyReturnStr):
        self.__moneyCondition = float(moneyConditionStr)
        self.__moneyReturn = float(moneyReturnStr)
    def accept_cash(self,money):
        result = money
        if (money >= self.__moneyCondition):
            result = money - money // self.__moneyCondition * self.__moneyReturn
        return result

class CashContext(object):
    def __init__(self,typ):
        self.cs = CashSuper()
        if typ == "正常收费":
            self.cs = CashNormal()
        elif typ == "满300返100":
            self.cs = CashReturn()
            self.cs.cash_return("300","100")
        elif typ == "打8折":
            self.cs = CashRebate()
            self.cs.cash_rebate("0.8")
        
    def get_result(self,money):
        return self.cs.accept_cash(money)

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
        self.combobox['value'] = ("正常收费","打8折","满300返100")
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
        csuper = CashContext(self.comboVar.get())
        totalPrice = csuper.get_result(float(self.txtPrice.get()) * float(self.txtNum.get()))
        self.total = self.total + totalPrice
        self.ibxList.insert('end',"单价："+self.txtPrice.get()+" 数量："
                            +self.txtNum.get()+" "+self.comboVar.get()+" 合计：%.2f"%(totalPrice)+"\n")
        self.iblResult.set("%.2f"%self.total)
        self.refresh()

if __name__ == '__main__':
    CashWindow()
