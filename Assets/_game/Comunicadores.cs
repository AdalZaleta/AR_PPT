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
    public float disapear;
    public Material mt;
    public ParticleSystem ps;
    bool doOnce = true;

    private void Start()
    {
        mt = gameObject.GetComponent<Renderer>().material;
    }


    private void OnEnable()
    {
        ms.AddActivo(gameObject);
    }

    private void OnDisable()
    {
        ms.RemoveActivo(gameObject);
        doOnce = true;
    }

    public void Disapear()
    {
        disapear = 0;
        if (doOnce)
        {
            doOnce = false;
            ps.Play();
        }
        DOTween.To(() => disapear, x => disapear = x, 1, 2.0f).OnUpdate(() => { mt.SetFloat("_Noise_Slider", disapear); });
    }
}
