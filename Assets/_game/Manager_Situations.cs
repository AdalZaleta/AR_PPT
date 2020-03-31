using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using TMPro;

public class Manager_Situations : MonoBehaviour
{
    public TextMeshProUGUI texto;
    public GameObject Hacha1;
    public GameObject Hacha2;
    public GameObject Espada1;
    public GameObject Espada2;
    public GameObject Lanza1;
    public GameObject Lanza2;

    public List<GameObject> Activos;

    void Awake()
    {
        Activos = new List<GameObject>();
    }

    Comunicadores com1, com2;

    // Update is called once per frame
    void Update()
    {
        com1 ??= Activos[0].gameObject.GetComponent<Comunicadores>();
        com2 ??= Activos[1].gameObject.GetComponent<Comunicadores>();
        if (Activos.Count > 1)
        {
            texto.text = "Estan en escena:\n" + com1.type
                    + "\n y \n" + com2.type;
            if (Vector3.Distance(Activos[0].transform.position, Activos[1].transform.position) < 1.0f)
            {
                texto.text = "ESTAN CERCA:\n" + com1.type
                    + "\n y \n" + com2.type;
                if (com1.type == typeWeapon.Sword &&
                    com2.type == typeWeapon.Sword)
                {
                    //Empate
                    com1.Disapear();
                    com2.Disapear();
                }
                if (com1.type == typeWeapon.Sword &&
                    com2.type == typeWeapon.Axe)
                {
                    //Gana Espada
                    com2.Disapear();
                }
                if (com1.type == typeWeapon.Sword &&
                    com2.type == typeWeapon.Spear)
                {
                    //Gana Lanza
                    com1.Disapear();
                }
                if (com1.type == typeWeapon.Axe &&
                    com2.type == typeWeapon.Sword)
                {
                    //Gana Espada
                    com1.Disapear();
                }
                if (com1.type == typeWeapon.Axe &&
                    com2.type == typeWeapon.Axe)
                {
                    //Empate
                    com1.Disapear();
                    com2.Disapear();
                }
                if (com1.type == typeWeapon.Axe &&
                    com2.type == typeWeapon.Spear)
                {
                    //Gana Hacha
                    com2.Disapear();
                }
                if (com1.type == typeWeapon.Spear &&
                    com2.type == typeWeapon.Sword)
                {
                    //Gana Lanza
                    com2.Disapear();
                }
                if (com1.type == typeWeapon.Spear &&
                    com2.type == typeWeapon.Axe)
                {
                    //Gana Hacha
                    com1.Disapear();
                }
                if (com1.type == typeWeapon.Spear &&
                    com2.type == typeWeapon.Spear)
                {
                    //Empate
                    com1.Disapear();
                    com2.Disapear();
                }
            }
        }
        else if(Activos.Count == 0)
        {
            texto.text = "No hay objetos En la escena";
        }
        else if(Activos.Count == 1)
        {
            texto.text = "Estan en escena:\n" + com1.type;
        }
        Debug.Log("Numero de Objetos Activos: " + Activos.Count);
    }

    public void AddActivo(GameObject _g)
    {
        Activos.Add(_g);
    }

    public void RemoveActivo(GameObject _g)
    {
        Activos.Remove(_g);
    }
}
