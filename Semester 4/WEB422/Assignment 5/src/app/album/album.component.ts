import { Component, OnDestroy, OnInit } from '@angular/core';
import { MatSnackBar } from '@angular/material/snack-bar';
import { ActivatedRoute } from '@angular/router';
import { MusicDataService } from '../music-data.service';


@Component({
  selector: 'app-album',
  templateUrl: './album.component.html',
  styleUrls: ['./album.component.css']
})
export class AlbumComponent implements OnInit, OnDestroy {

  album: any;
  albumSub: any;
  id:any;
  idSub: any;

  constructor(private snackBar : MatSnackBar, private route: ActivatedRoute, private musicDataService: MusicDataService) { }

  ngOnInit(): void {
    this.id = this.route.snapshot.params['id'];
    this.albumSub = this.musicDataService.getAlbumById(this.id).subscribe(data => {
      return this.album = data;
    });
  }

  addToFavourites(trackID : any){
    if(this.musicDataService.addToFavourites(trackID)){
      this.snackBar.open("Adding to Favourites...", "Done", {duration: 1500});
    }
  }

  ngOnDestroy(){
    this.albumSub?.unsubscribe();
  }
}
