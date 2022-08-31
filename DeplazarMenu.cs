using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DeplazarMenu : MonoBehaviour
{
    public RectTransform menutransform;
    public Vector3 Desplazo;
    void Start()
    {
        
    }

    void Update()
    {
        
    }

    public void DesplazarMenuIzq()
    {
        menutransform.position -= Desplazo;
    }

    public void DesplazarMenuDer()
    {
        menutransform.position += Desplazo;
    }
}
