//
// Created by HuRF on 2022/9/20.
//

#include "GameRoleMemento.h"


int main() {
    // 大战Boss前
    GameRoleMemento * lixiaoyao = new GameRoleMemento();
    lixiaoyao->GetInitState();
    lixiaoyao->StateDisplay();

    // 保存进度
    RoleStateCaretaker * stateAdmin = new RoleStateCaretaker();
    stateAdmin->SetRoleStateMemento(lixiaoyao->SaveState());

    // 大战Boss时，损耗严重
    lixiaoyao->Fight();
    lixiaoyao->StateDisplay();

    // 恢复之前状态
    lixiaoyao->RecoveryState(stateAdmin->GetRoleStateMemento());
    lixiaoyao->StateDisplay();

    return 0;
}