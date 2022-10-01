# -*- coding:utf-8 -*-
'''
@File    :   Memento.py
@Time    :   2022/09/28 16:21:39
@Author  :   SheltonXiao
@Version :   1.0
@Contact :   pi620903@163.com
@Desc    :   None
'''
# 角色状态存储箱
class RoleStateMemento(object):
    __vit = None
    __atk = None
    __def = None
    def __init__(self,vit,atk,defe):
        self.__vit = vit
        self.__atk = atk
        self.__def = defe
    def get_vit(self):
        return self.__vit
    def set_vit(self,vit):
        self.__vit = vit
    def get_atk(self):
        return self.__atk
    def set_atk(self,atk):
        self.__atk = atk
    def get_def(self):
        return self.__def
    def set_def(self,defe):
        self.__def = defe
    vitality = property(get_vit,set_vit)
    attack = property(get_atk,set_atk)
    defense = property(get_def,set_def)

# 游戏角色
class GameRole(object):
    __vit = None
    __atk = None
    __def = None
    def get_vit(self):
        return self.__vit
    def set_vit(self,vit):
        self.__vit = vit
    def get_atk(self):
        return self.__atk
    def set_atk(self,atk):
        self.__atk = atk
    def get_def(self):
        return self.__def
    def set_def(self,defe):
        self.__def = defe
    vitality = property(get_vit,set_vit)
    attack = property(get_atk,set_atk)
    defense = property(get_def,set_def)
    def state_display(self):
        print("角色当前状态：")
        print(f"体力：{self.__vit}")
        print(f"攻击力：{self.__atk}")
        print(f"防御力：{self.__def}")
        print("")
    def get_init_state(self):
        self.__vit = 100
        self.__atk = 100
        self.__def = 100
    def fight(self):
        self.__vit = 0
        self.__atk = 0
        self.__def = 0
    def save_state(self):
        return RoleStateMemento(self.__vit,self.__atk,self.__def)
    def recovery_state(self,memento:RoleStateMemento):
        self.__vit = memento.vitality
        self.__atk = memento.attack
        self.__def = memento.defense

# 角色状态管理者
class RoleStateCaretaker(object):
    __memento = None
    def get_memento(self):
        return self.__memento
    def set_memento(self,memento):
        self.__memento = memento
    memento = property(get_memento,set_memento)


if __name__ == '__main__':
    # 大战Boss前
    lixiaoyao = GameRole()
    lixiaoyao.get_init_state()
    lixiaoyao.state_display()

    # 保存进度
    stateAdmin = RoleStateCaretaker()
    stateAdmin.memento = lixiaoyao.save_state()

    # 大战Boss时，损耗严重
    lixiaoyao.fight()
    lixiaoyao.state_display()

    # 恢复之前状态
    lixiaoyao.recovery_state(stateAdmin.memento)
    lixiaoyao.state_display()