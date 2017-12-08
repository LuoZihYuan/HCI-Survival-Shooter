using UnityEngine;
using System.Collections;
using UnityEditor;

[CustomEditor(typeof(Arduino))]
public class ArduinoEditor : Editor
{
	public override void OnInspectorGUI()
	{
		DrawDefaultInspector();

		Arduino arduino = (Arduino)target;

		GUILayout.Label("Custom Buttons");

		GUILayout.BeginHorizontal();
		if(GUILayout.Button("Update Servos"))
		{
			arduino.WriteDegsToSerial();
		}
		if(GUILayout.Button("Reset"))
		{
			arduino.Reset();
		}
		GUILayout.EndHorizontal();
	}
}