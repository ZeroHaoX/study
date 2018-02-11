using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class StartUI : MonoBehaviour {
    public Text best;
    public Text last;
    public Toggle Blue;
    public Toggle Yellow;
    public Toggle Border;
    public Toggle Free;

    void Awake()
    {
        last.text = "上次：长度" + PlayerPrefs.GetInt("lastl", 0) + ",分数:" + PlayerPrefs.GetInt("lasts",0);
        best.text = "最好：长度" + PlayerPrefs.GetInt("bestl", 0) + ",分数:" + PlayerPrefs.GetInt("bests",0);
    }

    void Start()
    {
        if(PlayerPrefs.GetString("sh","sh01")=="sh01")
        {
            Blue.isOn = true;
            PlayerPrefs.SetString("sh", "sh01");
            PlayerPrefs.SetString("sb", "sb0101");
            PlayerPrefs.SetString("sb1", "sb0102");
        }
        else
        {
            Yellow.isOn = true;
            PlayerPrefs.SetString("sh", "sh02");
            PlayerPrefs.SetString("sb", "sb0201");
            PlayerPrefs.SetString("sb1", "sb0202");
        }

        if(PlayerPrefs.GetInt("border",0)==0)
        {
            Border.isOn = true;
            PlayerPrefs.SetInt("border", 0);
        }
        else
        {
            Free.isOn = true;
            PlayerPrefs.SetInt("border", 1);
        }
    }

    public void gamestar()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene(1);
    }


    public void Blueselect(bool ison)
    {
        if (ison)
        {
            PlayerPrefs.SetString("sh", "sh01");
            PlayerPrefs.SetString("sb", "sb0101");
            PlayerPrefs.SetString("sb1", "sb0102");
        }
    }
    public void Yellowselect(bool ison)
    {
        if (ison)
        {
            PlayerPrefs.SetString("sh", "sh02");
            PlayerPrefs.SetString("sb", "sb0201");
            PlayerPrefs.SetString("sb1", "sb0202");
        }

    }
    public void Borderselect(bool ison)
    {
        if (ison)
            PlayerPrefs.SetInt("border", 0);
    }
    public void Freeselect(bool ison)
    {
        if (ison)
            PlayerPrefs.SetInt("border", 1);
    }
}
