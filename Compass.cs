using System.Collections;
using System.Collections.Generic;
using System.IO.Ports;
using System.Runtime.InteropServices;
using UnityEngine;


public class Compass : MonoBehaviour
{
    SerialPort stream = new SerialPort("COM4", 115200);
    // Start is called before the first frame update
    void Start()
    {
        stream.Open();
    }

    // Update is called once per frame
    void Update()
    {
        string value = stream.ReadLine();
        Debug.Log(value);
        float deg = float.Parse(value);
        transform.localRotation = Quaternion.Euler(deg,-90,90);
    }
}
