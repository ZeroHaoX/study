using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Bulletcontrol : MonoBehaviour {
    void Start()
    {
        StartCoroutine("Bulletdestroy");
    }

    IEnumerator Bulletdestroy()
    {
        yield return new WaitForSeconds(1.5f);
        Destroy(this.gameObject);
    }
}
