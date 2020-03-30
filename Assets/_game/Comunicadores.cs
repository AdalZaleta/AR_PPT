using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Comunicadores : MonoBehaviour
{
    public Manager_Situations ms;
    private void OnEnable()
    {
        ms.AddActivo(gameObject);
    }

    private void OnDisable()
    {
        ms.RemoveActivo(gameObject);
    }
}
