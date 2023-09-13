// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <iostream>
#include "mem.h"
/*
Layout 
f1 health
f2 Freeze currentAmmo
f3 gerande

*/

/*
Health 0xEC
Armor 0xF0
X = 0x28, Y = 0x2C Z = 0x30
*/

//class entity {
//public:
//    int health = 0xEC;
//    int ammo;
//    char name[16] = "0x205";
//};

void printMenu(bool health, bool ammo, bool jump, bool fastMove, bool recoil, bool fastShoot) {
    //
    std::cout << "------- gak -------" << std::endl;
    std::cout << "[F1] Update Health " << health << std::endl;
    std::cout << "[F2] Update Ammo " << ammo << std::endl;
    //std::cout << "[F3] High Jump " << jump << std::endl;
    //std::cout << "[F4] Move Fast " << fastMove << std::endl;
    //std::cout << "[F5] No Recoil " << recoil << std::endl;
    //std::cout << "[F6] Shoot Fast " << fastShoot << std::endl;

}

DWORD WINAPI hackThread(HMODULE hModule) {
    AllocConsole();
    FILE* f;
    freopen_s(&f, "CONOUT$", "w", stdout);

    std::cout << "OG for a fee, stay sippin' fam\n";

    const uintptr_t modBase = (uintptr_t)GetModuleHandle(L"ac_client.exe");
    const uintptr_t* localPlayer = (uintptr_t*)(modBase + 0x10F4F4);
    int* localHealth = reinterpret_cast<int*>(*localPlayer + 0xF8);
    int* localArmor = reinterpret_cast<int*>(*localPlayer + 0xFC);
    int* localPrimaryAmmo = reinterpret_cast<int*>(*localPlayer + 0x150);
    int* localPraimryReserve = reinterpret_cast<int*>(*localPlayer + 0x128);
    int* localSecondaryAmmo = reinterpret_cast<int*>(*localPlayer + 0x13C);
    int* localSecondaryReserve = reinterpret_cast<int*>(*localPlayer + 0x0114);
    int* localGernadeAmmo = reinterpret_cast<int*>(*localPlayer + 0x158);
    //Update to 1.2.0.2
    //uintptr_t* entityList = reinterpret_cast<uintptr_t*>(modBase + 0x18AC04);
    std::cout << localPlayer;
    bool bHealth = false;
    bool bAmmo = false;
    bool bJump = false;
    bool bFastmove = false;
    bool bRecoil = false;
    bool bShootFast = false;

    printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);

    // Dereference for things *(int*)(*localPlayer + 0xEC) = 1337
    while (true) {
        if (GetAsyncKeyState(VK_F1) & 1) {
            bHealth = !bHealth;
            if (bHealth) {
                printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
                *localHealth = 9999;
                *localArmor = 9999;
            }
            else {
                *localHealth = 100;
                *localArmor = 100;
            }
        }
        if (GetAsyncKeyState(VK_F2) & 1) {
            bAmmo = !bAmmo;
            if (bAmmo) {
                printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
                *localPrimaryAmmo = 9999;
                *localPraimryReserve = 9999;
                *localSecondaryAmmo = 9999;
                *localSecondaryReserve = 9999;
                *localGernadeAmmo = 9999;
            }
        }
        //if (GetAsyncKeyState(VK_F3) & 1){
        //    bJump = !bJump;
        //    if (bJump) {
        //        
        //        printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
        //        mem::Patch((BYTE*)(modBase + 0xC2486), (BYTE*)"\xC7\x46\x18\x00\x00\x00\x42", 7);
        //        
        //    }
        //    else {
        //        printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
        //        mem::Patch((BYTE*)(modBase + 0xC2486), (BYTE*)"\xC7\x46\x18\x00\x00\x00\x40", 7);
        //    }
        //}
        //if (GetAsyncKeyState(VK_F4) & 1) {
        //    bFastmove = !bFastmove;
        //    if (bFastmove) {
        //        printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
        //        mem::Patch((BYTE*)(modBase + 0xBFCB8), (BYTE*)"\xC6\x40\x74\x04", 4);
        //    }
        //    else {
        //        printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
        //        mem::Patch((BYTE*)(modBase + 0xBFCB8), (BYTE*)"\xC6\x40\x74\x01", 4);
        //    }
        //}
        //if (GetAsyncKeyState(VK_F5) & 1) {
        //    bRecoil = !bRecoil;
        //    if (bRecoil) {
        //        printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
        //        mem::Nop((BYTE*)(modBase + 0xC8E52), 5);
        //        mem::Nop((BYTE*)(modBase + 0x68490), 5);

        //    }
        //    else {
        //        printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
        //        mem::Patch((BYTE*)(modBase + 0xC8E52), (BYTE*)"\xF3\x0F\x11\x50\x40", 5);
        //        mem::Patch((BYTE*)(modBase + 0x68490), (BYTE*)"\xB8\x01\x00\x00\x00", 5);

        //    }
        //}
        //if (GetAsyncKeyState(VK_F6) & 1) {
        //    bShootFast = !bShootFast;
        //    if (bShootFast) {
        //        printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
        //        mem::Nop((BYTE*)(modBase + 0xC73EA), 2);
        //        mem::Nop((BYTE*)(modBase + 0xC73EF), 2);
        //    }
        //    else {
        //        printMenu(bHealth, bAmmo, bJump, bFastmove, bRecoil, bShootFast);
        //        mem::Patch((BYTE*)(modBase + 0xC73EA), (BYTE*)"\x89\x08", 2);
        //        mem::Patch((BYTE*)(modBase + 0xC73EF), (BYTE*)"\xFF\x08", 2);
        //    }
        //}
        //if (GetAsyncKeyState(VK_F7) & 1) {
        //    entity ent[32];
        //    ent[0] = entity();
        //    int j = 4;
        //    for (int i = 0; i < 32; i++) {
        //        int* entList = reinterpret_cast<int*>(*entityList);
        //        std::cout << "Entity: " << i << " Has " << (*entList + j) + ent[i].health << " Health" << std::endl;
        //        j += 4;
        //        if (i == 32) {
        //            j = 0;
        //        }
        //    }
        //}

        if (GetAsyncKeyState(VK_END) & 1) {
            break;
        }
    }

    if (f) { fclose(f); };
    FreeConsole();
    FreeLibraryAndExitThread(hModule, 0);
    return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{

    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        CloseHandle(CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)hackThread, hModule, 0, nullptr));
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

