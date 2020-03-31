using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using DG.Tweening;

public enum typeWeapon
{
    Sword = 0,
    Axe = 1,
    Spear = 2
};

public class Comunicadores : MonoBehaviour
{
    public Manager_Situations ms;
    public typeWeapon type;


    private void OnEnable()
    {
        ms.AddActivo(gameObject);
    }

    private void OnDisable()
    {
        ms.RemoveActivo(gameObject);
    }

    public void Disapear()
    {
        
    }
}
