using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class UImanager : MonoBehaviour {
    public Text Score;
    public Text Shoot;

    public int scores = 0;
    public int shoots = 0;
    private static UImanager instant;
    public static UImanager Instant
    {
        get
        {
            return instant;
        }
    }
    

    void Awake()
    {
        instant = this;
    }

    void Update()
    {
        Score.text = "得分:" + scores;
        Shoot.text = "射击数:" + shoots;
    }

    public void scorer()
    {
        scores += 5;
    }

    public void shooter()
    {
        shoots += 1;
    }
}
