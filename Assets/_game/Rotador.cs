using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Rotador : MonoBehaviour
{
    public float rotationSpeed;
    // Update is called once per frame
    void Update()
    {
        transform.Rotate(Vector3.back * (rotationSpeed * Time.deltaTime));
    }
}
