import { Component, OnInit } from '@angular/core';
import { NgForm } from '@angular/forms';
import { AuthService } from '../auth.service';
import RegisterUser from '../RegisterUser';

@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {

  registerUser: RegisterUser = {userName: "", password: "", password2: ""};
  warning: String = "";
  success: Boolean = false;
  loading: Boolean = false;

  constructor(private auth: AuthService) { }

  ngOnInit(): void {
  }

  onSubmit(f: NgForm){
    if(this.registerUser.userName != "" && this.registerUser.password != "" && this.registerUser.password2 != "" ){
      this.loading = true;
      // this.auth.register(this.registerUser).subscribe((msg) => {
      //   this.success = true;
      //   this.warning = "";
      //   this.loading = false;
      // }, (err) => {
      //   this.success = false;
      //   this.warning = err.error.message;
      //   this.loading = false;        
      // })
      this.auth.register(this.registerUser).subscribe(
        { complete: () => {
          this.success = true;
          this.warning = "";
          this.loading = false;
        }, error: (e) => {
          this.success = false;
          this.warning = e.error.message;
          this.loading = false;
        }}
      )
    }
  }
}
