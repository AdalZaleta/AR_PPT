using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Comunicadores : MonoBehaviour
{
    private void OnEnable()
    {
        SendMessage("AddActivo", gameObject);
    }

    private void OnDisable()
    {
        SendMessage("RemoveActivo", gameObject);
    }
}
