﻿using System.Collections;
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

    // Update is called once per frame
    void Update()
    {
        if(Activos.Count > 1)
        {
            texto.text = "Estan en escena:\n" + Activos[0].gameObject.GetComponent<ImageTargetController>().TargetName
                    + "\n y \n" + Activos[1].gameObject.GetComponent<ImageTargetController>().TargetName;
            if (Vector3.Distance(Activos[0].transform.position, Activos[1].transform.position) < 0.5f)
            {
                texto.text = "ESTAN CERCA:\n" + Activos[0].gameObject.GetComponent<ImageTargetController>().TargetName
                    + "\n y \n" + Activos[1].gameObject.GetComponent<ImageTargetController>().TargetName;
            }
        }
        else if(Activos.Count == 0)
        {
            texto.text = "No hay objetos En la escena";
        }
        else if(Activos.Count == 1)
        {
            texto.text = "Estan en escena:\n" + Activos[0].gameObject.GetComponent<ImageTargetController>().TargetName;
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