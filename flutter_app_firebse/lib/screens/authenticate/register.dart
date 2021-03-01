import 'package:flutter/material.dart';
import 'package:flutter_app_firebse/services/auth.dart';
class Register extends StatefulWidget {
  final Function toggleView;
  Register({this.toggleView});
  @override
  _RegisterState createState() => _RegisterState();
}

class _RegisterState extends State<Register> {
  final AuthService _auth = AuthService();
  String email="";
  String password="";
  String error="";
  final _formKey = GlobalKey<FormState>();
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text("Sign up in my app"),
        actions: <Widget>[
          FlatButton.icon(onPressed: (){
                widget.toggleView();
              },
              icon: Icon(Icons.person),
              label: Text("Sign in")),
        ],
      ),
      body: Container(
        padding: EdgeInsets.symmetric(vertical: 20.0, horizontal: 50.0),
        child: Form(
          key: _formKey,
          child: Column(
            children: <Widget>[
              SizedBox(height: 20.0),
              TextFormField(
                decoration: InputDecoration(
                  hintText: "Email",
                ),
                validator: (val)=>val.isEmpty?"Enter an email":null,
                onChanged: (val){
                  setState(()=>email=val);
                },
              ),
              SizedBox(height: 20.0),
              TextFormField(
                decoration: InputDecoration(
                  hintText: "Password",
                ),
                obscureText: true,
                validator: (val)=>val.length<6?"Enter a password of more than 6 char":null,
                onChanged: (val){
                  setState(()=>password=val);
                },
              ),
              SizedBox(height: 20.0),
              RaisedButton(
                child: Text("Register"),
                onPressed: () async {
                  if(_formKey.currentState.validate()){
                    dynamic result = await _auth.registerWithEmailAndPassword(email, password);
                    if(result==null){
                       setState(()=>error="please enter a valid email");
                    }
                  }
                },
              ),
              SizedBox(height: 12.0,),
              Text(error),
            ],
          ),
        ),
      ),
    );
  }
}
